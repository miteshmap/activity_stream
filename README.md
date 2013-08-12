googlenews_views
================

Drupal 6 Googlenews_views

Ability to generate xml that is accepted by googlenews sitemap Here is the detail of how it should be formatted
https://support.google.com/webmasters/answer/74288?hl=en

We have added this functionality to be configured using views. 
Here are the steps to follow to generate xml for googlenews sitemap


1) Enable the module

2) Go to views and create a view with your node

3) Add fields like node title, path, category, tags etc.

4) select the row style - Google News data document

5) after that you will see a configuration form where you can select which field you want to use as title, path, date etc..

6) save the path of your views something like  - news.xml or googlenews.xml


That's it. your googlenews.xml path is ready to submit on google.
