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

#### Aside: 'the bad old days'

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

In the left-hand-side 'project pane', on the same level as the blue `src` folder, right click our project's top-level `Calculator` folder and create a new sub directory called `tests`.

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/testing_figs/tests_folder.png" width="500">

Now we're going to 'mark' this folder as a special directory where **all** tests for the classes in our project will be placed. To do this, click the project structure icon located in the upper right hand corner of the IDE:

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/testing_figs/project_structure.png" width="500">

With the project structure window open, navigate to 'modules' then select the `tests` folder you created from the hierarchy, then click the green `Tests` folder icon next to "Mark as: ..". You should see the tests folder you created turn green, indicating that this is where all of your test classes will live.

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/testing_figs/mark.png" width="700">

When finished, click apply then 'OK' and that should close the project structure window.

Now return to the project pane and right click and add a package that mirrors the one created in the blue `src` folder. Then create a class called `TestCalculator` within this package. It's good practice to have the package structure of this test-directory mirror closely that of your project (makes it easier to organize -- and hence find -- any `TestXXXX.java` classes you might make).

So when all is said and done, your project pane should look like this (folder colors and all):

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/testing_figs/tests_pkg.png" width="500">

|Aside: marked directories|
|-------------|
|*IntelliJ uses [marked directories (or, in IntelliJ speak: 'Content Roots')](https://www.jetbrains.com/help/idea/2016.2/configuring-content-roots.html) as a means of distinguishing certain folders based on type of files they contain. Blue `src` folders are typically created for you when you start a new project. This is where all of your source files (.java and Java packages) should be placed, while green folders distinguish the outermost directory where all your tests will live (which can also -- of course -- contain `.java` files and Java packages). It is rare to have one 'marked' directory within another.. That is, they should exist independently at the top level of your project (i.e.: they should almost always be the immediate children of the top level project directory -- which in the case of this tutorial, is the folder named 'Calculator' ... not to be confused with the Java class!)*|

### Writing tests

Now we're ready to write some tests for our `add` and `mult` methods. For now, just copy the content below into your `TestCalculator` class.

```java 
package edu.clemson.cpsc215;

public class TestCalculator extends TestCase {

    private Calculator calc;

    @Before  // runs before each test marked with an @Test annotation
    public void setUp() { calc = new Calculator(); }

    @After //runs after each method marked with an @Test annotation
    public void tearDown() { calc = null; }

    @Test
    public void testAdd() {
        assertEquals("testing add(3,4)", 7, calc.add(3,4));
    }
}
```

Once you've copied (or perhaps as you're typing the above) you'll notice that IntelliJ doesn't really seem to know what JUnit is, or what you're trying to say:

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/testing_figs/junit_error.png" width="500">

To fix this, you need to add a version of JUnit to your classpath. One easy way to do this is to simply click the cursor on one of the red pieces of text such as the `@Test` annotation then press `alt + enter` and it will bring up a box asking if you want to add JUnit4 (or 3, either is fine) to the classpath -- click that.

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/testing_figs/add_to_classpath.png" width="400">

If a box pops up asking you something along the lines of which distribution of JUnit you'd like to use, just select the one from "IntelliJ IDEA distribution".

Once this is done, add the following imports to your `TestCalculator` class. In the end it should look like this:

```java
package edu.clemson.cpsc215;

import junit.framework.TestCase;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class TestCalculator extends TestCase {
    /* same as previous ... */
}
```

### Executing the tests in `TestCalculator`

Now we want to run this test class to see if the assertions we make in our `@Test` methods hold. Doing so is a lot like running ordinary programs in IntelliJ -- that is, you will need to create a JUnit specific run-configuration for the class (or classes) you're trying to test.

To do so, first select new configuration:

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/testing_figs/runconfig1.png" width="500">

click the plus icon and select `JUnit`:

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/testing_figs/runconfig2.png" width="500">

In the configuration menu that pops up, give the configuration a name, and point it to your `TestCalculator` class.

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/testing_figs/runconfig3.png" width="500">

|Aside: package wide testing & dependency management systems|
|-------------|
*Exploring some of the options in this configuration screen, you'll notice that you can also create configurations capable of automatically finding and testing all JUnit test classes in a given package (as well its sub-packages). Build systems such as [Maven](https://maven.apache.org/) and [Gradle](https://gradle.org/), if configured to do so, will automatically invoke tests like these as projects are deployed/compiled. These so called dependency management and build systems are extremely powerful and useful, but often come with a steep learning curve and are thus a whole other topic in their own right.*|

Now that we have a JUnit run configuration, all we have to do is press the green play button next to it to run our tests:

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/testing_figs/runconfig4.png" width="500">

All green should make you feel good, as it indicates that your class (or classes) pass their test cases :)  

Note if you're too lazy (I am usually) to manually create the run configuration, IntelliJ will automatically construct one for you if you simply click the circular play button next to the class definition for `TestCalculator`:

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/testing_figs/lazy.png" width="800">

