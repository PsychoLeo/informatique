import subprocess
from random import randint

t = 100
xlim = 10

for i in range(t):
    assert xlim > 5
    n = randint(5, xlim)
    
    # Generate input file
    with open("input", "w") as f:
        f.write(str(n) + '\n')
        for _ in range(n):
            a = randint(1, n)
            b = randint(a, n)
            f.write(str(a) + ' ' + str(b) + '\n')
    
    # Run first command and check for errors
    with open("input", "r") as infile, open("output", "w") as outfile:
        result_exec = subprocess.run("./exec", stdin=infile, stdout=outfile)
    if result_exec.returncode != 0:
        print(f"Error running ./exec on test {i+1}")
        break
    
    # Run second command and check for errors
    with open("input", "r") as infile, open("output-good", "w") as outfile_good:
        result_naif = subprocess.run(["python3", "manteau-naif.py"], stdin=infile, stdout=outfile_good)
    if result_naif.returncode != 0:
        print(f"Error running manteau-naif.py on test {i+1}")
        break

    # Compare outputs
    result_diff = subprocess.run(["diff", "output-good", "output"], capture_output=True, text=True)
    if result_diff.stdout:
        print(f"Error found on test {i+1}")
        print(result_diff.stdout)
        break
