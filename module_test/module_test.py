from subprocess import Popen, PIPE, STDOUT
import sys


def run_test(nme, ti):
    RED   = "\033[1;31m"
    GREEN = "\033[0;32m"
    RESET = "\033[0;0m"

    test_run = Popen(['./../build/toyRobot'], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
    cmd = ti.readline().rstrip()
    cmdList = []
    while('Output' != cmd[0:6]):
        print("Sending command: "+cmd)
        cmdList.append(cmd)
        cmd = ti.readline().rstrip()
    result = test_run.communicate(('\n'.join(cmdList)).encode())
    x = result[0].rstrip().decode().split('\n')[-1]
    print(x)
    if x == cmd[8:].rstrip():
        sys.stdout.write(GREEN)
        print(nme+': PASS\n')
        sys.stdout.write(RESET)
    else:
        sys.stdout.write(RED)
        print(nme+': FAIL')
        sys.stdout.write(RESET)
        print('Expected '+cmd[8:]+', got '+x+'\n')


print('Starting toyRobot Test')
ti = open("test_input.txt")

for line in ti:
    if line.rstrip():
        test_name = line
        print("Start Test: "+test_name)
        run_test(test_name, ti)
    
ti.close()
