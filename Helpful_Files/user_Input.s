.data  # data segment
Msg1X:    
.string "\nEnter x: "  # Prompt for x 

Msg1M:    
.string "\nEnter m: "  # Prompt for x 

Msg1B:    
.string "\nEnter b: "  # Prompt for x 


outMsgX:    
.string "\nThe value of x is:  "  # Output message    

outMsgM:    
.string "\nThe value of m is:  "  # Output message  

outMsgB:    
.string "\nThe value of b is:  "  # Output message  


.bss # uninitialized variables segment    
	.lcomm m, 2   
	.lcomm x, 2   
	.lcomm b, 2   
.text  # code segment
.global main
main:      

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
	
# Prompt user for   
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


# Output Message  m
	movq $4, %rax       # sys_write    
	movq $1, %rbx       # $1 is stdout    
	movq $outMsgM, %rcx  # output message    
	movq $21, %rdx      # length of the message    
	int  $0x80          # system interrupt to kernel    

# Output m    
	movq $4, %rax       # sys_write    
	movq $1, %rbx       # $1 is stdout    
	movq $m, %rcx       # output x    
	movq $0x1, %rdx     # length of the message    
	int  $0x80          # system interrupt to kernel   

# Output Message  x
	movq $4, %rax       # sys_write    
	movq $1, %rbx       # $1 is stdout    
	movq $outMsgX, %rcx  # output message    
	movq $21, %rdx      # length of the message    
	int  $0x80          # system interrupt to kernel 
	
# Output x    
	movq $4, %rax       # sys_write    
	movq $1, %rbx       # $1 is stdout    
	movq $x, %rcx       # output x    
	movq $0x1, %rdx     # length of the message    
	int  $0x80          # system interrupt to kernel  

# Output Message  b
	movq $4, %rax       # sys_write    
	movq $1, %rbx       # $1 is stdout    
	movq $outMsgB, %rcx  # output message    
	movq $21, %rdx      # length of the message    
	int  $0x80          # system interrupt to kernel 

# Output b    
	movq $4, %rax       # sys_write    
	movq $1, %rbx       # $1 is stdout    
	movq $b, %rcx       # output x    
	movq $0x1, %rdx     # length of the message    
	int  $0x80          # system interrupt to kernel  
	
	
# Exit with return 0    
	movl $1, %eax       # exit(0) - $1 is sys_exit    
	movl $0, %ebx       # 0 is return value    
	int  $0x80          # system interrupt to kernel    
	ret
