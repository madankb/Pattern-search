Pattern-search
==============
Hashing :- Creating a unique ID for a string and assigning to it is called as hashing.

Example :- "the" = (t.(26)^2 + h.(26)^2 + e), 26 is the base because alphabets has 26 letters, so by this way a unique ID can be assigned to a word.

           "523" = 5*10^2 + 2*10^1 + 3*10^0 = 523, 10 is the base for numbers(0...9), so by this way a unique ID is generated for the number which is the number itself.
	   
	   "523" = 5*256^2 + 2*256^1 + 3*256^0 = 327680 + 512 + 3 = 328195, 256 is the base for ASCII characters, so a unique ID is assigned for the string of ASCII characters.
	   
	   "GEEK" = 71*256^3 + 69*256^2 + 69*256^1 + 75^256^0, 71,69,75 are ASCII decimal values of the character "GEEK".

Issue in hashing :-

        1) As the length of the string get longer, the value generated for it also be get bigger. So it can't be stored in the integer data type, because the limit of the integer 
           data type is -2,147,483,648 to 2,147,483,647 for signed integer and 0 to 4,294,967,295 for unsigned integer in 32 bit machine. Values bigger than that can't be stored.
	   
	      2) So the unique number generated needs to be limited to the size of the data type. It can be acheived by modulo operation, so the number results from the modulo also should
           be unique.
       
        3) Choosing the right prime number for modular operand can give unique ID for some extension, but still collision in hashing is unavoidable. Two different strings has same hash. 
           http://computinglife.wordpress.com/2008/11/20/why-do-hash-functions-use-prime-numbers/

        4) Since the collision is unavoidable, once the hash code matches the string is iterated over to find if the tring really matches.
