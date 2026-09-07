# GDB Assignment Calculator and Expression Processing

## Phase 1

### 1.Install GDB and verify that it is available from the terminal

```bash
sudo apt update
```

```bash
sudo apt install gdb
```

- **g++ --version** – compiler version check for c++ program

- **gdb --version** – gdb installation check

![GDB assignment screenshot](images/screenshot_01.png)

- Check the location of the gdb and g++ by : **which gdb** & **which g++**

![GDB assignment screenshot](images/screenshot_02.png)

---

### 2. Create the project with calculator.cpp, calculator.h, main.cpp and README.md

- Create a new directory : **mkdir calculator-gdb**

- Change the directory : **cd calculator-gdb**

- Create files : **touch calculator.h calculator.cpp main.cpp README.md**

- Compile using : **g++ main.cpp calculator.cpp –o calculator**

![GDB assignment screenshot](images/screenshot_03.png)

---

### 3. Create both debug and release build and use the –g option for the debug build. Record the difference in the executable/debugging information

- Debug build → contains debugging symbols and no optimization.

- Release build → optimized for execution and normally has no debugging symbols

- Create the Debug build :

```bash
g++ -g -O0 main.cpp calculator.cpp -o calculator_debug
```

Here:

-g → adds debugging information for GDB.

-O0 → disables compiler optimization, making debugging easier.

-o calculator_debug → output executable name.

- Check : **ls -lh calculator_debug**

- Create the Release build :

```bash
g++ -O2 main.cpp calculator.cpp -o calculator_release
```

Here:

-O2 → enables compiler optimizations.

No -g → debugging information is not intentionally included.

-o calculator_release → creates the release executable.

- check : **ls -lh calculator_release**

![GDB assignment screenshot](images/screenshot_04.png)

- Check debugging information

![GDB assignment screenshot](images/screenshot_05.png)

- Here the calculator_debug compiled with –g produced debug information while the calculator_release build without –g have no debugging information

- The functionality of both the executable are same but the build characteristics are different

- Debug builds preserve information and code structure needed for source-level debugging, while Release builds prioritize optimized execution.

---

### 4. Start the application through GDB and practice to run, continue, step into, step over, step out and finish.

- To Start the application : **gdb -tui ./calculator_debug**

- Create breakpoints : used to stop when execution reaches that particular location

![GDB assignment screenshot](images/screenshot_06.png)

- Now run using : **run 5 + 10**

![GDB assignment screenshot](images/screenshot_07.png)

- This starts **./calculator_debug 5 + 10** and stops at main

- To continue execution in main : **continue or c**

- So gdb continues execution until it reaches next breakpoint, i.e, calculate

![GDB assignment screenshot](images/screenshot_08.png)

```text
Step Into : Now to step into calculate() use step command, this steps into applyOperator() called by calculate()
```

![GDB assignment screenshot](images/screenshot_09.png)

```text
Step Over : next command executes the current line without entering another function
```

![GDB assignment screenshot](images/screenshot_10.png)

```bash
Step Out : to leave the function finish command is used and return to calculate()
```

![GDB assignment screenshot](images/screenshot_11.png)

---

### 5. Set line, function and functional breakpoints, list active breakpoints and remove at least one breakpoint.

- To set a line breakpoint : **break main.cpp:20**

![GDB assignment screenshot](images/screenshot_12.png)

- To set a function breakpoint : **break function_name**

![GDB assignment screenshot](images/screenshot_13.png)

- This breakpoint will trigger whenever calculate() is called.

- To list active breakpoints : **info breakpoints**

![GDB assignment screenshot](images/screenshot_14.png)

- Run the program :

![GDB assignment screenshot](images/screenshot_15.png)

- After we use run command, the program executes until it encounters the breakpoint one, on continue command it executes until it reaches next breakpoint and it goes on till the program completes execution.

- To Remove a breakpoint : **delete breakpoint_number**

![GDB assignment screenshot](images/screenshot_16.png)

delete 1 : this command deletes the breakpoint 1 which is a line breakpoint

- use disable when you want to keep a breakpoint but temporarily prevent it from stopping execution.

---

### 6. Run the calculator with command-line arguments and inspect the input, intermediate values and final result.

- Open the editor and run the program with gdb enabled

![GDB assignment screenshot](images/screenshot_17.png)

- Set a breakpoint at main and run the program with arguments

```text
To inspect arguments : info args

The arguments are:

argv[0] = "./calculator_debug"

argv[1] = "10"

argv[2] = "+"

argv[3] = "5"

Therefore, argc = 4
```

- Can use : **print argc or p argc & print argv or p argv**

![GDB assignment screenshot](images/screenshot_18.png)

![GDB assignment screenshot](images/screenshot_19.png)

- Add a breakpoint at main.cpp:19, and inspect the input variables :

![GDB assignment screenshot](images/screenshot_20.png)

- Add a breakpoint at calculate() and inspect the intermediate results :

![GDB assignment screenshot](images/screenshot_21.png)

- Now type next and inspect the result :

![GDB assignment screenshot](images/screenshot_22.png)

- Now type finish and see the final result value in main.cpp :

![GDB assignment screenshot](images/screenshot_23.png)

- We can also use this command to set arguments

```bash
set args 10 + 5

run
```

![GDB assignment screenshot](images/screenshot_24.png)

---

### 7. Use print, display and expression evaluation to inspect operands, operators and calculated values.

- Set a breakpoint at calculate() and inspect the operands, operators and calculated values:

![GDB assignment screenshot](images/screenshot_25.png)

- Expression Evaluation :

![GDB assignment screenshot](images/screenshot_26.png)

- This does not modify the program, simply evaluates and shows the result

- display tells GDB : Show this expression automatically whenever execution stops.

![GDB assignment screenshot](images/screenshot_27.png)

```bash
info display :
```

![GDB assignment screenshot](images/screenshot_28.png)

- To remove a display : **undisplay 3**

- To remove all displays : **delete display**

---

### 8. Use info locals and info args to inspect the current function state.

- Set a breakpoint at calculate and run 10 – 2 : info args displays the arguments passed to the function and info locals display the local variables in the current function state.

![GDB assignment screenshot](images/screenshot_29.png)

---

### 9. Use backtrace and stack-frame navigation to understand the call path when an error occurs

- backtrace tells how the execution reached this state in frames

![GDB assignment screenshot](images/screenshot_30.png)

- To navigate among the stack frames : frame stack_frame_number

![GDB assignment screenshot](images/screenshot_31.png)

- Use info args and info locals to inspect the variable among the stack frames

---

### 10. Inspect source code directly from GDB and navigate between relevant source locations.

- Set a breakpoint and run the program, use list to display the source around the current location

![GDB assignment screenshot](images/screenshot_32.png)

- To specify a line range : **list 19,40**

![GDB assignment screenshot](images/screenshot_33.png)

- To view a particular function : **list function_name**

![GDB assignment screenshot](images/screenshot_34.png)

- To navigate to a specific source location : **list main.cpp:19**

![GDB assignment screenshot](images/screenshot_35.png)

- Use frame to identify the source location :

![GDB assignment screenshot](images/screenshot_36.png)

---

### 11. Use a watchpoint to detect when a result variable changes unexpectedly

- Set a breakpoint at calculate and set the result as watch variable and use next command, if the result variable changes the value gets displayed.

![GDB assignment screenshot](images/screenshot_37.png)

---

### 12. Create a controlled infinite-loop condition and use GDB to identify the loop condition and the iteration at which the program stops making progress.

![GDB assignment screenshot](images/screenshot_38.png)

- Use list to find the error :

![GDB assignment screenshot](images/screenshot_39.png)

![GDB assignment screenshot](images/screenshot_40.png)

- Open the Editor and fix the issue and test the output:

![GDB assignment screenshot](images/screenshot_41.png)

---

### 13. Distinguish between a logical error and runtime error and record how the debugging approach differs.

- Logical Error:
  - Perform a multiplication operation :

![GDB assignment screenshot](images/screenshot_42.png)

- The result should be 50 but it is 15, so it is a logical error, look through the file and find and correct the error.

- Apply a breakpoint and look at the args to the function

![GDB assignment screenshot](images/screenshot_43.png)

- List the current location :

![GDB assignment screenshot](images/screenshot_44.png)

- The error is in case ‘\*’ , resolve and recompiler and verify the result :

![GDB assignment screenshot](images/screenshot_45.png)

- Runtime Error: Attempts to write to memory through a null ptr

![GDB assignment screenshot](images/screenshot_46.png)

- Resolve the error and recompile to verify the result

---

### 14 . Add application logging for selected operations and compare what can be learned from logs versus an interactive GDB session.

- Create a log file and for every operation add a log :

![GDB assignment screenshot](images/screenshot_47.png)

```text
What did the log tell us?

Operation → 10 / 0

Operator  → /

Problem   → Division by zero

Result    → 0
```

- So the log lets us identify the failure after the operation has occurred.

![GDB assignment screenshot](images/screenshot_48.png)

- In GDB debug :

![GDB assignment screenshot](images/screenshot_49.png)

- Lets you to inspect interactively, useful when reproducing failure, shows variables and execution state, live program state.

- Logging tells you what the application recorded. GDB lets you investigate the live program state and execution path.

---

## Phase 2

### 1. Debug an incorrect calculation

- Set breakpoints at main.cpp and calculator.cpp files

![GDB assignment screenshot](images/screenshot_50.png)

- Inspect the variables :

![GDB assignment screenshot](images/screenshot_51.png)

- Observation : the problem is not in arguments

```text
List and see the code logic :
```

![GDB assignment screenshot](images/screenshot_52.png)

- Set a breakpoint in the main calculation :

![GDB assignment screenshot](images/screenshot_53.png)

- Now it is find that the code contains intermediate value as 5, and that causes the problem

- Inspect the call stack :

![GDB assignment screenshot](images/screenshot_54.png)

```text
The root cause is the use of – instead of + :

double intermediate = left - right;

Fix the defect to :

double intermediate = left + right;
```

- Recompile and verify the results

---

### 2. Debug and Infinite loop

- Introduce bug: Remove i++

```code
while (i < 5)
{
    std::cout << "Iteration: " << i << '\n';
}
```

Compile:

```bash
g++ -g -O0 main.cpp calculator.cpp -o calculate_debug
```

Start GDB:

```bash
gdb -tui ./calculator_debug
```

Run and inspect:

```bash
set debuginfod enabled off

break calculate
```

```bash
run 10 + 5

list calculate
```

```bash
break calculator.cpp:<loop-line>

continue

print i
```

```bash
print i < 5

watch i
```

- i remains 0 and i < 5 remains true.

- Conditional breakpoint if i == 3 is never reached.

- Press Ctrl+C to interrupt the infinite loop.

- Root cause: i is never incremented.

Fix:

```code
while (i < 5)
{
    std::cout << "Iteration: " << i << '\n';

    i++;
}
```

- Recompile and test. Expected iterations: 0 to 4, followed by Result:

- Observation: GDB showed that i stayed at 0, confirming the missing increment as the cause of the infinite loop.

![GDB assignment screenshot](images/screenshot_38.png)

- Use list to find the error :

![GDB assignment screenshot](images/screenshot_39.png)

![GDB assignment screenshot](images/screenshot_40.png)

- Open the Editor and fix the issue and test the output:

![GDB assignment screenshot](images/screenshot_41.png)

---

### 3. Debug a segmentation fault :

- On running, received segmentation fault :

![GDB assignment screenshot](images/screenshot_55.png)

- Segmentation fault occurs when we try to access an invalid memory

- On backtracing, found the error occurred from calculate(), inspect the stack frame

![GDB assignment screenshot](images/screenshot_56.png)

![GDB assignment screenshot](images/screenshot_57.png)

- On inspecting, the ptr points to null and frame 0 shows the issue from calculate() and on list the error is found from the current source file

- Fix the program :

![GDB assignment screenshot](images/screenshot_58.png)

![GDB assignment screenshot](images/screenshot_59.png)

---

### 4. Debug a multi-file failure

- Found error in result value

![GDB assignment screenshot](images/screenshot_60.png)

- Inspect the source file :

![GDB assignment screenshot](images/screenshot_61.png)

![GDB assignment screenshot](images/screenshot_62.png)

- Error from applyOperator() helper function

- Use frame 0 along with list to inspect the source file

![GDB assignment screenshot](images/screenshot_63.png)

- Resolve, recompile, rerun and verify:

![GDB assignment screenshot](images/screenshot_64.png)

- Compare logging and Debugging

- Create a log file and for every operation add a log :

![GDB assignment screenshot](images/screenshot_47.png)

```text
What did the log tell us?

Operation → 10 / 0

Operator  → /

Problem   → Division by zero

Result    → 0
```

- So the log lets us identify the failure after the operation has occurred.

![GDB assignment screenshot](images/screenshot_48.png)

- In GDB : shows live variables, call stack, source, and execution state.

![GDB assignment screenshot](images/screenshot_65.png)

![GDB assignment screenshot](images/screenshot_66.png)

- Limitations of Logging
  - Records only predefined information.

  - Cannot inspect unlogged variables.

  - Cannot control program execution.

  - May not reveal the exact root cause.

- Advantages of Interactive Debugging
  - Inspects variables in real time.

  - Allows breakp+oints and step-by-step execution.

  - Shows call stack and source code.

  - Helps identify the exact root cause.
