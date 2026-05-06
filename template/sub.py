import subprocess

subprocess.run(["g++", 'template/sub.cpp'])
result = subprocess.run(['./a.out'],
        capture_output=True, input='6 7 4 4'.encode())
print(result.stdout.decode())