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
    * **search** {_user_}
*  **EXAMPLES**
    * **search -user=@beyonce**
      <br> Found @beyonce in local database.
    * **search -user=@doesnotexist**
      <br> Could not find @doesnotexist in local database.
*  **DEFAULTS**
    * N/A
*  **FLAGS & OPTIONS**
    * **-user=** : Specifies user to lookup
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
    * N/A
---
*  **NAME**
    * dpoints : Displays number of data points in local dataset
*  **SYNOPSIS**
    * **dpoints** {_username_}
*  **EXAMPLES**
    * **dpoints**
      <br> 25,000
    * **dpoints -all**
      <br> 25,000
    * **dpoints -user=@beyonce**
     <br> 8,542
*  **DEFAULTS**
    * **dpoints** : Displays total data points in local dataset 
*  **OPTIONS**
    * **-all** : Displays number of data points for all users in local database

## 2. Analyzing Data

---
*  **NAME**
    * sort : Displays sorted lists of posts and the time complexity used to sort posts
*  **SYNOPSIS**
    * sort {**sorting method**} {_username_} {_metric_} {_emoji_} {_lines-to-display_} 
*  **EXAMPLES**
    * **sort -merge -all**
    <br> Displays top 20 posts with the most number of emojis used in a caption, analyzing all users in local database and sorting captions
    using mergesort. The first column displayed is the caption and the second column is the number of emojis in the caption. 
    * **sort -merge -user=@beyonce**
    <br> Displays @beyonce's top 20 posts with the most emojis used in caption and the number of emojis used in the caption
    * **sort -merge -user=@beyonce -emoji=red-heart**
    <br> Displays @beyonce's top 20 posts with the most red-heart emojis used in caption and the number of times the heart-emoji was used in the caption
    * **sort -merge -user=@beyonce -emoji=red-heart 50**
    <br> Displays @beyonce's top 20 posts with the most red-heart emojis used in caption and the number of times the heart-emoji was used in the caption
*  **DEFAULTS**
    * user_name = all
    * metric = usage
    * emoji = none
    * lines-to-display = 20
*  **OPTIONS**
    * **-merge** : Performs mergesort on captions
    * **-quick** : Performs quicksort on captions
    * **-all** : Analyzes posts from all users in local database
    * **-user=@{_user_}** : Analyzes posts from specified user. If user doesn't exist in database, prints error message and recommends list command
    * **-usage** : Sorts captions the number of emojis used in post
    * **-emoji={_emoji_}** : Specifies emoji to sort by. If emoji doesn't exist, prints error message.
    * **-lines={_int_}** : Specifies number of lines. If option value is not a positive integer, prints error message. 
---

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
*  **FLAGS & OPTIONS**
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