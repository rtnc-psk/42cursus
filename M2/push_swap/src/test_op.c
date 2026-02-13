#include "../include/push_swap.h"
#include <stdio.h>

void    print_stacks(t_stack *stack_a, t_stack *stack_b)
{
    printf("\n--- STATUS ---\n");
    printf("Stack A:\n");
    while (stack_a)
    {
        printf("%d (idx: %d)\n", stack_a->value, stack_a->index);
        stack_a = stack_a->next;
    }
    printf("Stack B:\n");
    while (stack_b)
    {
        printf("%d (idx: %d)\n", stack_b->value, stack_b->index);
        stack_b = stack_b->next;
    }
    printf("--------------\n\n");
}

// //for main

// 	printf(">>> STARTING STATE <<<\n");
//     print_stacks(stack_a, stack_b);

//     // --- TEST 1: PUSH (pb) ---
//     printf(">>> TEST: pb (Push 1 to B) <<<\n");
//     pb(&stack_a, &stack_b);
//     print_stacks(stack_a, stack_b);

//     printf(">>> TEST: pb (Push 2 to B) <<<\n");
//     pb(&stack_a, &stack_b);
//     print_stacks(stack_a, stack_b);

//     // --- TEST 2: SWAP (sa) ---
//     // At this point, A should be [3, 4, 5]
//     printf(">>> TEST: sa (Swap top of A) <<<\n");
//     sa(&stack_a);
//     print_stacks(stack_a, stack_b);

//     // --- TEST 3: ROTATE (ra) ---
//     // At this point, A should be [4, 3, 5] (after swap)
//     printf(">>> TEST: ra (Rotate A up) <<<\n");
//     ra(&stack_a); 
//     // Expect: 3 is top, 5 is middle, 4 is bottom.
//     print_stacks(stack_a, stack_b);

//     // --- TEST 4: REVERSE ROTATE (rra) ---
//     printf(">>> TEST: rra (Rotate A down) <<<\n");
//     rra(&stack_a);
//     // Expect: Should return to previous state (4 at top).
//     print_stacks(stack_a, stack_b);
    
//     // --- TEST 5: PUSH BACK (pa) ---
//     printf(">>> TEST: pa (Push top of B back to A) <<<\n");
//     pa(&stack_a, &stack_b);
//     print_stacks(stack_a, stack_b);
