# Java Development with IntelliJ IDEA: A quick usage guide

<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/jetbrains_logo_detail.jpg" width="400">

IntelliJ IDEA is a powerful IDE built by a company called [Jetbrains](https://www.jetbrains.com/) for developing and maintaining Java projects of all sizes. While it is comparable to Eclipse, this document avoids getting into a lengthy discussion on the merits of each; for that, consult one or more of the many articles (re: blogs) online such as 
* https://dzone.com/articles/why-idea-better-eclipse 
* https://www.quora.com/What-is-best-IDE-IntelliJ-IDEA-vs-Eclipse-for-Java-development
* https://blog.jetbrains.com/idea/2016/03/enjoying-java-and-being-more-productive-with-intellij-idea/ .

Consequently, this document is by no means intended to be a complete (or even partial) guide to using this IDE -- in fact it doesn't even scratch the surface. So to really take advantage of the features offered, you'll likely need to search online for more detailed instructions on how to carry out certain IDE operations (such as refactor-renaming, finding all implementations of a given interface, etc). 

This guide is therefore really only intended to help get the IDE downloaded, installed, and setup for a simple "Hello World" project. The pictures accompanying each step assume the current version of the community edition (2016.2.1).

## Required downloads

You should download the latest version of the Java Development Kit (JDK) from [here](http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html) as well as the (free) community edition of the IDE itself, available to download [here](https://www.jetbrains.com/idea/#chooseYourEdition). The IDE supports windows, mac, and linux. 

First install the JDK downloaded from Oracle's website. Once this is done, installation of IntelliJ should simply be a matter of clicking the .exe, .dmg, etc and following the default prompts (Note: If you're runnning linux *I think* you need to run the shell script `idea.sh` located in the tarball or whatever package you downloaded to get the installation rolling, though I could be wrong -- so consult Google for more help with that).

## Creating a simple `Hello World` project

1. Upon first starting up the IDE, you might get a popup box asking if you want to import settings from a previous version, (unless you have a prior version) simply select "I don't have a prior version.." and click next.
<img src="https://github.com/dtwelch/misc/blob/master/handouts/intellij/figs/intellij_import_mac.jpg" width="400">

