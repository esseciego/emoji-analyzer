# Command Manual

## 0. Key

---
*  **bold text** : Type exactly as shown
*  _italic text_ : Replace with appropriate argument
*  {**-abc**} : Any or all arguments within { } are optional

## 1. Managing Local Database

---
*  **NAME**
    * search : Checks if user exists in local database
*  **SYNOPSIS**
    * **search** _user_ 
*  **EXAMPLES**
    * **search @beyonce**
      <br> Found @beyonce in local database.
    * **search @doesnotexist**
      <br> Could not find @doesnotexist in local database.
*  **DEFAULTS**
    * N/A
*  **OPTIONS**
    * N/A
---
*  **NAME**
    * list : Lists users in local database
*  **SYNOPSIS**
    * **list**
*  **EXAMPLES**
    * **list**
      <br> @beyonce
      <br> @nickiminaj
      <br> @shakira
*  **DEFAULTS**
    * list : Lists all users in local database
*  **OPTIONS**
    * **-all** : Lists all users in local database. 
---
*  **NAME**
    * num : Displays number of data points in local dataset
*  **SYNOPSIS**
    * **num** {_metric_} {_username_}
*  **EXAMPLES**
    * **num @beyonce**
      <br> 8,542
    * **num --data-points**
      <br> 25,000
    * **num --data-points -all**
      <br> 25,000
*  **DEFAULTS**
    * **num -d**, **num --data-points** : Displays total number of data points in database (num == 4 * postsCount)
*  **OPTIONS**
    * **-d**, **--data-points** : Displays number of data-points in dataset
    * **@_username_** : Displays value for a specified user. If user doesn't exist, prints error message and recommends "list" command.
    * **-all** : Displays number of data points for all users in local database

## 2. Analyzing Data

---
*  **NAME**
    * mergesort : Displays lists of posts and their emoji usage
*  **SYNOPSIS**
    * **mergesort** **{_username_}** **_metric_** {sorting order} {_lines to display_} {short name} 
*  **EXAMPLES**
    * **mergesort** **@beyonce** **--usage** 
    <br> Displays @beyonce's top 20 posts with the most emojis used in caption and the number of emojis used
    * **mergesort** **-all** **--usage**
    <br> Displays top 20 posts from all users in local database's with the most emojis used in caption and the number of emojis used
    * **mergesort** **-all** **-u** **:red-heart:**
    <br> Displays top 20 posts from all users with the most red-heart emojis used in caption and the number of emoji appeared
    * **mergesort** **-all** **-u** **:red-heart:** **-r** **50** **-name**
    <br> Displays top 20 posts from all users with the least red-heart emojis used in caption and the number of emoji appeared. Emojis are replaced by their shortname
*  **DEFAULTS**
    * **mergesort {_username_} _metric_** : Displays first 20 sorted posts
*  **OPTIONS**
    * **@_username_** : Analyzes posts from specified user. If user doesn't exist in database, print error message and recommends "list" command.
    * **-all** : Analyzes posts from all users in local database
    * **-u, --usage** : Sort posts by number of emojis used per post (emoji count per post >= 0)
    * **-u _:emoji:_, --usage _:emoji:_**: Sorts posts by number of specified emoji used per post. If emoji doesn't exist in Unicode-16, prints error message and links to list of Unicode emojis  
    * **-r, --reverse** : Sorts posts in ascending/reverse order 
    * **_n_** (positive int) : Print n posts to console. If n exceeds number of posts, prints error message and number of posts a user has / in local database. 
    * **-name** : Prints English shortname for emoji instead of graphical representation 

---
*  **NAME**
    * quicksort : Displays sorted emojis and their specified metric value using merge sort
*  **SYNOPSIS**
    * **mergesort** **{_username_}** **_metric_** {sorting order} {_lines to display_} {short name}
*  **EXAMPLES**
    * See quicksort
*  **DEFAULTS**
    * See quicksort
*  **OPTIONS**
    * See quicksort

## 3. Getting Help

---
*  **NAME**
    * man : Displays command manual
*  **SYNOPSIS**
    * **man**
*  **EXAMPLES**
    * N/A
*  **DEFAULTS**
    * N/A
*  **OPTIONS**
    * N/A

---
*  **NAME**
    * --help : Displays program's description and purpose
*  **SYNOPSIS**
    *  **(no arguments), -h,--help**,
*  **EXAMPLES**
    * N/A
*  **DEFAULTS**
    * N/A
*  **OPTIONS**
    * N/A