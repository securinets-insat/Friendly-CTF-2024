def digit_sum(n):
    return sum(int(digit) for digit in str(n))

def check_conditions(number):
    num_str = str(number)
    
    if len(num_str) < 7:
        return False
    
    left_sum = int(num_str[0]) + int(num_str[1]) + int(num_str[2])
    right_sum = int(num_str[3]) + int(num_str[4]) + int(num_str[5])
    
    if not (left_sum > right_sum and right_sum > int(num_str[6]) + 3):
        return False
    
    for index, digit in enumerate(num_str):
        digit_value = int(digit)
        if index % 2 == 0:
            if digit_value % 2 != 0:
                return False
        else:
            if digit_value % 2 != 1:
                return False
    
    return True

def generate_and_check_numbers():
        for num in range(4567000, 4568000):
            if digit_sum(num) == 33:
                if check_conditions(num):
                    print(f"Valid number found: {num}")

if __name__ == "__main__":
    generate_and_check_numbers()
