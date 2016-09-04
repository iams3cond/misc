# Unit Testing with JUnit in IntelliJ

The purpose of these notes is to give a practical demonstration as to how one might go about organizing, writing, and automating 'formal' test cases for your classes and methods using the IntelliJ IDE -- which comes packaged with the de-facto testing framework for Java: *JUnit*. 

Before getting started, it's worth mentioning that just as my [IntelliJ setup instructions](https://github.com/dtwelch/misc/blob/master/handouts/intellij/intellij_setup.md) were not intended to be a comprehensive survey on the features and capabilities of IntelliJ, this document is not intended to be a comprehensive survey on the subject of testing itself, or on the usage of JUnit for that matter. For more information on these topics -- unit testing, black box, white box testing, etc -- you should refer to the class notes/slides. 

To this end however, there are several places I attempt to illustrate *why* testing frameworks like JUnit are useful and preferable over the alternative. These places appear in "**Aside**" titled subsections.

## A simple example

We'll create a new project with a package containing a simple calculator class, and an alternate one where our test cases will be placed. The proceeding steps will walk you through this.

### Setup

First, fire up IntelliJ and create a new Java project called `Calculator`. Once you've gotten through all of the introductory matter and your new (empty) Calculator project is loaded up and waiting, go to the left-side 'project' pane and right-click the blue `src` folder. Then select the new Package option:

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

#### Aside: the 'bad old days'

Prior to the existence of testing frameworks like JUnit, one might've also included a `main()` in the above class, like the one shown below.

```java
public static void main(String[] args) {
    Calculator calc = new Calculator();
    // test add
    if (calc.add(3, 4) != 7) { System.err.println("error: add(3, 4)"); }
    if (calc.add(0, 4) != 4) { System.err.println("error: add(0, 4)"); }
    ...
}
```

I'd argue this an ad-hoc approach for several reasons:

* The usage of `System.err` as a means of communicating 'failed tests' or 'passed tests' by itself doesn't provide any useful information (such as expected vs actual output) -- rather, it places the burden of giving useful information associated with each test case squarely on the shoulders of those writing the actual tests. That is, how well the testing framework communicates results is dependent on how much time those writing the tests gave towards presenting such info. 

* The many `If`s make the code and tests harder to read.

* Couples test code to the rest of your (production) code. This is inefficient, unprofessional, and often unnecessary. 

* By manually writing `if`s around each test, users (in this case: those writing tests) in some sense are doing the work that a testing harness/framework should be doing behind the scenes. That is, the nitty-gritty code for the `if` statements would ideally be parcelled out to a separate module -- out of sight and out of mind. 

* When your code is deployed and built, if class `Calculator` is merely used by other classes, and does not serve as the main entrypoint, its `main` will never get executed when the final jar containing the project is constructed -- and hence the tests you worked so hard on won't get invoked automatically when its time to deploy -- what if bugs have creeped in since the last time that particular `main()` was invoked?

Some of these might seem pretty picky at first, but once you've started writing some tests in JUnit, you'll hopefully begin to recognize and appreciate some of the advantages it offers over the above.

### Create a 'tests' directory

In the left-hand-side 'project pane', on the same level as the blue `src` folder, right click on the `Calculator` folder and create a new directory called `tests`.

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/testing_figs/tests_folder.png" width="500">

Now we're going to 'mark' this folder as a special directory where **all** tests for the classes in our project will be placed. 
