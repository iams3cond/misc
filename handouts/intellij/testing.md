# Unit Testing with JUnit in IntelliJ

The purpose of these notes is to give a practical illstrution as to how one might go about organizing, writing, and automating tests for your classes and methods using the IntelliJ IDE -- which comes packaged with 'the' de-facto testing framework for Java: JUnit. 

Before getting starting, it's worth mentioning that just as my [IntelliJ setup instructions]() were not intended to be a comprehensive survey on the features and capabilities of IntelliJ, this document is not intended to be a comprehensive survey on the subject of testing itself or the usage of JUnit (for more information on these sorts of things -- unit testing, black box, white box testing, etc -- refer to the class slides). 

## A simple example

We'll create a new project with a package containing a simple calculator class, and an alternate one where our test cases will be placed.

### Setup

Fire up IntelliJ and create a new Java project called `Calculator`. Once you've gotten through all of the introductory matter and your new (empty) Calculator project is loaded, go to the 'project' pane and right click the blue `src` folder. Then select the new Package option:


Create the following package structure when the dialog box appears:




### Class `Calculator`

