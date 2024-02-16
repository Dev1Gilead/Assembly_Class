.data

#string values
Msg1X:    .string "\nEnter x: "  # Prompt for x 
Msg1M:    .string "\nEnter m: "  # Prompt for x 
Msg1B:    .string "\nEnter b: "  # Prompt for x 
final:    .string "\n\nResult: "  # Prompt for x 


#for formating printf (printing the final result)
format:
    .string "%ld\n"  # Format specifier for a long integer


# uninitialized variables    
.bss
	.lcomm m, 8  
	.lcomm x, 8   
	.lcomm b, 8  
	

.text


.global main
main:
        #starts the stack
    pushq   %rbp
    movq    %rsp,       %rbp
    

        # Prompt user for m    
	movq $4,        %rax # sys_write    
	movq $1,        %rbx # $1 is stdout    
	movq $Msg1M,     %rcx # message to write    
	movq $0x9,      %rdx # length of the message    
	int  $0x80      # system interrupt to kernel    

        # Read m    
	movq $3, %rax       # sys_read    
	movq $0, %rbx       # $0 is stdin    
	movq $m, %rcx       # m    
	movq $0x2, %rdx     # size    
	int $0x80           #system interrupt to kernel
	
	
        # Prompt user for x    
	movq $4,        %rax # sys_write    
	movq $1,        %rbx # $1 is stdout    
	movq $Msg1X,     %rcx # message to write    
	movq $0x9,      %rdx # length of the message    
	int  $0x80      # system interrupt to kernel   

        # Read x
	movq $3, %rax       # sys_read    
	movq $0, %rbx       # $0 is stdin    
	movq $x, %rcx       # x    
	movq $0x2, %rdx     # size    
	int $0x80           #system interrupt to kernel
	
        # Prompt user for b
	movq $4,        %rax # sys_write    
	movq $1,        %rbx # $1 is stdout    
	movq $Msg1B,     %rcx # message to write    
	movq $0x9,      %rdx # length of the message    
	int  $0x80      # system interrupt to kernel   
	
        # Read b
	movq $3, %rax       # sys_read    
	movq $0, %rbx       # $0 is stdin    
	movq $b, %rcx       # b    
	movq $0x2, %rdx     # size    
	int $0x80           #system interrupt to kernel

    # Load values into registers
    movq m, %rax
    movq x, %rsi
    movq b, %rdx
    
    # Subtract ASCII value of '0'
    sub $'0', %rax
    sub $'0', %rsi
    sub $'0', %rdx
    
    # Euation of a line
    imulq %rsi, %rax    # rax = rsi * rax 
    addq %rdx, %rax     # rax = rdx + rax
    
    #Save result to print later
    movq %rax, %rsi


	        # Final message  
	movq $4,        %rax # sys_write    
	movq $1,        %rbx # $1 is stdout    
	movq $final,     %rcx # message to write    
	movq $0x9,      %rdx # length of the message    
	int  $0x80      # system interrupt to kernel    


        #Print Final result
    movq $format, %rdi  # Address of the format string
    movq %rsi, %rdx     # Value to print moved into %rdx
    call printf         # Call printf 

    
        #puts 0 into rax, returns rax (return 0)
    movq    $0,         %rax
    leave
    ret


    #empty line to resolve warning
    