from z3 import *

s = Solver()

# Live

# Initialize a string with 19 characters
password = [BitVec(f'char{i}', 8) for i in range(19)]

# Verify that the password is alphanumeric or '-':
for i in range(len(password)):
    s.add(password[i] > ord(','))
    s.add(Or(password[i] <=  ord('-'), password[i] >  ord('/')))

    s.add(Or(password[i] <= ord('9') , password[i] > ord('@')))

    s.add(Or(And(password[i] <= ord('Z'), password[i] <= ord('z')) , And(password[i] > ord('`'), password[i] <= ord('z') )))

s.add(password[0] == ord('7'))
s.add(password[5] == ord('H'))
s.add(password[8] == ord('h'))
s.add(password[6] == ord('O'))
s.add(password[7] == ord('L'))
s.add(password[11] == ord('F'))
s.add(password[12] == ord('s'))


# love

v2 = (password[10] ^ password[8]) + ord('0')
v3 = (password[13] ^ password[5]) + ord('0')

s.add(And( v2 <= ord('9'), v3  <= ord("9")))
s.add(And(v2 > ord("/"), v3 > ord("/")))


s.add(Or(password[10] - password[8] == 7 , password[13] - password[5] == 7))

s.add(And((password[10] & password[8]) == 104 , (password[13] & password[5]) == 72))


s.add(And(v2 == password[3] , v2 == password[15]))

s.add(v3 == password[0])
s.add(v3 == password[18])


# laugh

v22 = password[2] + password[1];
v33 = password[17] + password[16];
v4 = password[2] - password[1];
v5 = password[17] - password[16];

s.add(And(v22 <= 170 , v33 <= 170))

s.add(v22 != v33)


s.add(Or(v4 == 6 , v5 == 13))

s.add(And((v5 ^ password[16]) == 68 , (v4 ^ password[1]) == 75))


#hacker

s.add(password[4] + password[14] + password[9] == 135)

s.add(password[14] == password[4])
s.add(password[4] == password[9])
s.add(password[9] == password[14])



s.add(password[16] == ord('I'))
s.add(password[17] == ord('V'))
s.add(password[3] == ord('7'))


def all_smt(s, initial_terms):
    def block_term(s, m, t):
        s.add(t != m.eval(t, model_completion=True))
    def fix_term(s, m, t):
        s.add(t == m.eval(t, model_completion=True))
    def all_smt_rec(terms):
        if sat == s.check():
           m = s.model()
           yield m
           for i in range(len(terms)):
               s.push()
               block_term(s, m, terms[i])
               for j in range(i):
                   fix_term(s, m, terms[j])
               yield from all_smt_rec(terms[i:])
               s.pop()

    yield from all_smt_rec(list(initial_terms))


# Print the solution 
for sol in all_smt(s, password):
    #sol = s.model()
    flag = [sol[f].as_long() for f in password]
    flag = ''.join(chr(c) for c in flag)
    print(flag)
