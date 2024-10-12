import time
import subprocess

program = './tryme'
PIN_LENGTH = 16

def try_pin(pin):
    start_time = time.time()
    process = subprocess.Popen([program], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    process.communicate(input=pin.encode())
    end_time = time.time()

    return end_time - start_time

def brute_force_pin():
    pin = ['0'] * PIN_LENGTH
    for i in range(PIN_LENGTH):
        timings = {}
        for digit in '0123456789':
            test_pin = ''.join(pin[:i] + [digit] + pin[i + 1:])
            elapsed_time = try_pin(test_pin)
            timings[digit] = elapsed_time
            print(f"Trying PIN {test_pin}: Time {elapsed_time:.5f}s")
        
        best_digit = max(timings, key=timings.get)
        pin[i] = best_digit
        print(f"Best guess for position {i+1}: {best_digit}")
    
    return ''.join(pin)

if __name__ == "__main__":
    cracked_pin = brute_force_pin()
    print(f"Cracked PIN: {cracked_pin}")