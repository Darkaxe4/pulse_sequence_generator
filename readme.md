# Pulse sequence generator
## Compiling 
```gcc -o <executable> generator.c pulses.c test_profiles.c ./external_dependencies/cJSON.c```
## Running
To run you need to specify testcases in testcases.json in working directory\
```./<executable>``` \
Output will be provided in .txt files with names specified at testcases file.

# Pulse sequence decoder
## Compiling
```gcc -o <executable> decoder.c```
## Running
```./<executable> <testcase_name>.txt``` \
Output will be provided in binary_sequence_out.txt where ```0``` means binary zero, ```1``` - binary one, ```-1``` - too short pulse, ```-2``` - end of sequence pulse