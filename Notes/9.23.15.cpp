//9.23.15 notes

Stack Application 

Evaluating expressions:
	
A tiny Language:
	()
	~ : not 
	& : and ^
	| : or  v
	> : implies ->
	= : equiv  <-> or =
	T : True
	F : False
	var. name 
	
	above is the order of preference 
	
	
	(p123 & ~q117) > ~(q143 | r12)
	
	Use 2 stacks: An op stack 
					An arg stack
		
	
	op arg 
	(
	i   p123
	&   q117
	~	
	
	op	arg 
	>	p123& ~q117
	~	
	(	q143
	
stacks are indispensable for doing operations 

*sp++ = x; //push
x = *-sp; //pop

-------

Another data struct


Queues 

Behavior 
0) Create empty Q
1) Check if empty 
2) enqueue (add an element to "end" of queue)
3) dequeue (remove oldest element on queue) 

0000000xxxxxxx00000
* b++ = x will add an x at the b
x = *f++ will move the front to the right, so the first element is gone
but if you continue this then you will run out 
so make it circular

how do we distinguish a fulll queue from an empty queue?

when empty AND full, Front = Back 
one solution is to only allow n-1 elements if size == n.
