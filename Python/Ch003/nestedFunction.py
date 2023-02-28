n = 42

def func():
    global n
    print(f"Within function: n is {n}")
    n = 3
    print(f"Within function: change n to {n}")
func()
print(f"Outside function: Value of n is {n}")