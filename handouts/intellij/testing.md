# Unit Testing with JUnit in IntelliJ

The purpose of these notes is to give a practical demonstration as to how one might go about organizing, writing, and automating 'formal' test cases for your classes and methods using the IntelliJ IDE -- which comes packaged with the de-facto testing framework for Java: *JUnit*. 

Before getting started, it's worth mentioning that just as my [IntelliJ setup instructions]() were not intended to be a comprehensive survey on the features and capabilities of IntelliJ, this document is not intended to be a comprehensive survey on the subject of testing itself, or on the usage of JUnit for that matter. For more information on these topics -- unit testing, black box, white box testing, etc -- you should refer to the class notes/slides. 

## A simple example

We'll create a new project with a package containing a simple calculator class, and an alternate one where our test cases will be placed. The proceeding steps will walk you through this.

### Setup

Fire up IntelliJ and create a new Java project called `Calculator`. Once you've gotten through all of the introductory matter and your new (empty) Calculator project is loaded up and waiting, go to the left-side 'project' pane and right-click the blue `src` folder. Then select the new Package option:


Create the following package structure when the dialog box appears (note that IJ will conveniently interpret usage of `.` in the name chosen as a nested package/folder):




### Class `Calculator`

