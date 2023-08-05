# emoji-analyzer
Project 3 : COP 3530

This project solution implements the Merge Sort and Quick Sort algorithms used in Project 3. The API is set up to run through a CaptionList object. The CaptionList object can then be used to evaluate the time it took to execute the two aforementioned sorting algorithms.

Basic Use:
1.  Create a CaptionList object using the parametrized constructor that takes in the name of the CSV file that contains the Instagram post data.
2.  Call a sorting function, either Merge Sort or Quick Sort.
3.  When either the Merge Sort or Quick Sort function is called, a timer is automatically started and stopped according to the calling and completion of the provided algorithm. The time is saved to a CaptionList variable, which can then be acessed using the corresponding CaptionList member function. This time value is automatically updated after every sorting call.


*NOTE* The test-unit is configured in a manner that assumes the proper Catch2 framework is installed.
*NOTE* Ensure the proper files are removed or commented out (test-unit/test.cpp & src/test.cpp) based on desired make configuration.
