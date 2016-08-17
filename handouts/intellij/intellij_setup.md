# Java Development with IntelliJ IDEA: A quick usage guide

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/jetbrains_logo_detail.jpg" width="400">

IntelliJ IDEA is a powerful IDE built by a company called [Jetbrains](https://www.jetbrains.com/) for developing and maintaining Java projects of all sizes. While it is comparable to Eclipse, this document avoids getting into a lengthy discussion on the merits of each; for that, consult one or more of the many articles (re: blogs) online such as 
* https://dzone.com/articles/why-idea-better-eclipse 
* https://www.quora.com/What-is-best-IDE-IntelliJ-IDEA-vs-Eclipse-for-Java-development
* https://blog.jetbrains.com/idea/2016/03/enjoying-java-and-being-more-productive-with-intellij-idea/ .

Consequently, this document is by no means intended to be a complete (or even partial) guide to using this IDE -- in fact it doesn't even scratch the surface. So to really take advantage of the features offered, you'll likely need to search online for more detailed instructions on how to carry out certain IDE operations (such as refactor-renaming, finding all implementations of a given interface, etc). 

This guide is therefore really only intended to help get the IDE downloaded, installed, and setup for a simple "Hello World" project. The pictures accompanying each step assume the current version of the community edition (2016.2.1).

## 1. Required downloads

You should download the latest version of the Java Development Kit (JDK) from [here](http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html) as well as the *free* community edition of the IDE itself, available [here](https://www.jetbrains.com/idea/#chooseYourEdition). The IDE supports windows, mac, and linux. 

|A note on the ulimate edition|
|-------------|
|*If your a student, I believe it's possible to obtain a year long license to the ultimate edition for free, though if I recall correctly you'll need to provide your Clemson email address (as proof I suppose). You'll have to do some digging on the Jetbrains website to find out how to initiate this. Needless to say, you won't need the ultimate edition for anything in this course, so it's probably best (re: faster/easier) to stick with the community edition -- which for all intents and purposes is exactly the same core IDE minus support for several web development frameworks (play, grail, react js, etc).*|

First install the JDK downloaded from Oracle's website. Once this is done, installation of IntelliJ should simply be a matter of clicking the .exe, .dmg, etc and following the default prompts (Note: If you're runnning Linux *I think* you need to run the shell script `idea.sh` located in the tarball or whatever package you downloaded to get the installation rolling, though I could be wrong -- so consult Google for more help with that).

## 2. Creating a simple `Hello World` project

1. Upon first starting up the IDE, you might get a popup box asking if you want to import settings from a previous version, (unless you have a prior version) simply select 'I don't have a prior version..' then click 'ok'.
<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/intellij_import_mac.png" width="500">

2. Next, you should be greeted by the following welcome page. Simply select 'Create New Project'.
 <img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/startup_screen.png" width="500">

3. The next screen you see should look something like this (for now, its O.K. if the 'Project SDK' box is empty).
 <img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/sdk_setup_page.png" width="500">

4. Now we need to tell the IDE which version of the Java SDK (software development kit) we want it to use for libraries and so forth. So click the 'new' button and select 'JDK' from the popup list. **You'll likely only need to do this once per machine, IDEA will remember any SDK's you've pointed it to for any future projects**.
<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/sdk_setup1.png" width="500">

5. This should bring up a another dialog box (shown below). Assuming you just used the default values when installing the java JDK in section 1 (meaning you simply clicked next at each step) this box should already have detected and automatically selected the right folder from the tree. So click 'Ok'. Once closed, click 'Next'
<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/sdk_setup2.png" width="400">

6. Keep clicking 'Next' until you get the following page
<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/naming_project.png" width="500">

7. Give your project a name, preferably something clever like 'hello'. Once finished, click 'Finish'. 
<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/naming_project2.png" width="500">

8. Once loaded, the you'll have a new, empty project -- and you're ready to start writing.
<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/empty_project.png" width="600">

9. Now we'll create a class containing a `main` function that prints `hello world`, then run it. To do this, first expand the `Hello` folder which should reveal an empty blue `src` folder: this is where all of our code will be placed.
<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/creating_class.png" width="300">

10. Next, right click on the blue `src` folder and select `new > Java Class`
<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/creating_class2.png" width="500">

11. Give the class a name, and click 'ok' (note that Java classes start with a capital letter).
<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/creating_class3.png" width="300">

12. Now write a `main` function with a print statement (like the one shown below). If all is well, there should be no error messages (such as things underlined in red).
<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/writing_code.png" width="600">

## 3. Running code

Programs can be run in all Jetbrain IDEs through *run configurations*. In this part of the walkthrough we'll create a simple run configuration for our hello world program then show how run configurations can be used to simulate arguments passed through the command line.

1. First select edit configurations from the dropdown box in the upper right hand corner.
<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/running_code.png" width="600">

2. Next, click the plus icon, then select 'Application'.
<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/running_code2.png" width="600">

3. Give the run configuration a name (it can be anything -- but ideally will describe the sort of program you want to run). Then point IntelliJ to the class which contains the `main` function. In this case, that class is `Hello`.
<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/running_code3.png" width="600">

4. Click 'Ok' then press the green play button to run the program 
<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/running_code4.png" width=500">

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/run_results.png" width=700">


