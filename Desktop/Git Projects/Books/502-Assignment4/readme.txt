Ben Pittman
CSS 502A Winter 2017

1. Runs with memory leaks.  

2. Implemented two hash tables - 
	a. patrondb is a hash table obeject that directly hashes into an array based on the patron ID number.  Collisions are not allowed, and are errors.
	b. catalog is an object of arrays of sets for storing library items.  The array is hashed into based upon the char of the library item type {Y, F, P}
	
3. librarian reads the book file data, uses the libitemfactory to set the objects, and calls virtual setData methods of libitem   derived classes to set the data. Librarian class calls libitemfactory to return a libitem object, and the object calls the 	   virtual methods of derived classes book, fictionbook, childrensbook and periodical to set their data members

4. librarian reads the command file data, uses the transactionfactory to set the data into objects, and calls the derived classes setTransaction methods to set the data to the proper derived class.  objects are then placed into a transactionQueue and called in a separate virtual execute() method that processes the transactions

5. A switch in the libitemfactory and another in the transactionitemfactory.  They violate the open-closed principle as if any additional library item or transaction types are added these objects will need to be modified.  Additionally, both the patronDB and catalog classes are limited in the number of objects they can store and would require some small changes to facilitate growth past 26 types of library items and above 10000 patrons as implemented.
