# Push_Swap
This Project is about creating a program which outputs the necessary moves to sort a stack of inputted integer parameters using only 2 stacks, Stack A and Stack B, in the smallest number of moves as possible.  
Read the [subject.pdf](https://github.com/Tempest989/Push_Swap/blob/main/en.subject.pdf) for in-depth information about the Project.
# My Score
<img width="1347" alt="Push_Swap Score" src="https://user-images.githubusercontent.com/55472613/178903689-ce1f6a27-f03d-45f3-b4e6-31bbc48241d9.png">

# Makefile Utility
- `make` and `make push_swap` will compile the Mandatory part of the Push_Swap Project, as the executable `push_swap`.
- `make bonus` will compile the Bonus part of the Push_Swap Project, as the executable `checker`.
- `make clean` will delete, if possible, the executable `push_swap`.
- `make fclean` will run `make clean` and then delete, if possible, the executable `checker`.
- `make re` will run the commands `make fclean`, `make` and `make bonus`.
# Code Execution Format
**Mandatory** = `./push_swap [set of integer numbers]`  
**Bonus** = `./checker [set of integer numbers]` or `./checker [set of integer numbers] < [file containing output commands from push_swap for this set of integer numbers]`
- Without using the input redirection, `<`, commands must be entered manually into terminal via standard input, 1 command at a time.
### Created and Used my Own [Push_Swap Tester](https://github.com/Tempest989/42_Push_Swap_Tester) to check if my code was working correctly for both Mandatory and Bonus.
