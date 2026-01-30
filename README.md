# H1 Students
Name: Alanis Castillo UFID: 18144408
Name: Graciela Strand UFID: 80178234

# H1  Instructions to run code
  1. Downlad github repo either by cloning or forking
  2. Reload Cmake project
  3. Compile and run main.cpp
  4. *Running main.cpp runs the matcher and verifier functions
  5.  Compile plot.py
     
# H1 Assumptions
- file input is a .txt file with space delimiters with new line between each list, the file also starts with n as the first value
- output is .txt file

# H1 Graph and solutions to part C
<img width="758" height="585" alt="verifer time N" src="https://github.com/user-attachments/assets/0daf5faa-59c2-4647-8160-523ce54821b9" />
<img width="787" height="597" alt="matching Time N" src="https://github.com/user-attachments/assets/51ce2797-bc94-4b57-a9db-d49eda4e7e02" />

The trend we notice is that both matcher and verifier follow a parabolic curve which follows that they are supposed to run in O(n^2) time at worse cases as mentioned in lecture, we were able to keep our
implementation. The smaller the N the faster the matcher and verifier ran but it was still an attainable time for large inputs of N such as n=512.
