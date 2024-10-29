import subprocess

# Define the commands
generate_command = ["python3", "gen3.py"]
naive_command = ["python3", "3-naive.py"]
cpp_command = ["compilecpp", "3-mots-justes.cpp"]
exec_command = ["./exec"]

t = 1000
# Run the loop up to 100 times
for i in range(t):
    # Run the generator script
    subprocess.run(generate_command)

    # Run the naive solution and store output to output-good
    with open("input", "r") as infile, open("output-good", "w") as outfile:
        subprocess.run(naive_command, stdin=infile, stdout=outfile)

    # Run the optimized solution and store output to output
    with open("input", "r") as infile, open("output", "w") as outfile:
        subprocess.run(exec_command, stdin=infile, stdout=outfile)

    # Compare output-good and output
    result = subprocess.run(["diff", "output-good", "output"], capture_output=True, text=True)

    # If there's a difference, print it and stop
    if result.stdout:
        print(f"Difference detected on attempt {i + 1}")
        print(result.stdout)  # Print the difference
        break
else:
    print(f"No differences detected after {t} attempts.")
