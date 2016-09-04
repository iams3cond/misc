# Unit Testing with JUnit in IntelliJ

The purpose of these notes is to give a practical demonstration as to how one might go about organizing, writing, and automating 'formal' test cases for your classes and methods using the IntelliJ IDE -- which comes packaged with the de-facto testing framework for Java: *JUnit*. 

Before getting started, it's worth mentioning that just as my [IntelliJ setup instructions](https://github.com/dtwelch/misc/blob/master/handouts/intellij/intellij_setup.md) were not intended to be a comprehensive survey on the features and capabilities of IntelliJ, this document is not intended to be a comprehensive survey on the subject of testing itself, or on the usage of JUnit for that matter. For more information on these topics -- unit testing, black box, white box testing, etc -- you should refer to the class notes/slides. 

## A simple example

We'll create a new project with a package containing a simple calculator class, and an alternate one where our test cases will be placed. The proceeding steps will walk you through this.

### Setup

Fire up IntelliJ and create a new Java project called `Calculator`. Once you've gotten through all of the introductory matter and your new (empty) Calculator project is loaded up and waiting, go to the left-side 'project' pane and right-click the blue `src` folder. Then select the new Package option:

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/testing_figs/click_pkg.png" width="800">

Create the following package structure when the dialog box appears (note that IJ will conveniently interpret usage of `.` in the name chosen as a nested package/folder):

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/testing_figs/name_pkg.png" width="400">

### Class `Calculator`

Right click inside this package and create a new class called `Calculator`:

```java
public class Calculator {

    public int add(int x, int y) { return x + y; }
    
    public int mult(int x, int y) { return x * y; }
}
```

Prior to the existence of testing frameworks like JUnit, one might've also included a `main()` in this program that looks something like this:
```java
public static void main(String[] args) {
    Calculator calc = new Calculator();
    // test add
    if (calc.add(3, 4) != 7) { System.err.println("error: add(3, 4)"); }
    if (calc.add(0, 4) != 4) { System.err.println("error: add(0, 4)"); }
    ...
}
```
