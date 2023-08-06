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
*  **DEFAULTS**
    * **dpoints** : Displays total data points in local dataset 
*  **OPTIONS**
    * **-all** : Displays number of data points for all users in local database

## 2. Analyzing Data

---
*  **NAME**
    * sort : Displays sorted lists of posts and the time complexity used to sort posts
*  **SYNOPSIS**
    * sort {**sorting method**}  
*  **EXAMPLES**
    * **sort -merge**
    <br> Displays top 20 posts with the most number of emojis used in a caption, analyzing all users in local database and sorting captions
    using mergesort. The first column displayed is the caption and the second column is the number of emojis in the caption. 
    * **sort -quick**
    <br> (Same displays as "-merge" but performs quicksort instead)
    * **sort -quick -lines=50**
    <br> Displays top 50 posts with the most used emojis in a caption
*  **DEFAULTS**
    * lines-to-display = 20
*  **OPTIONS**
    * **-merge** : Performs mergesort on captions
    * **-quick** : Performs quicksort on captions
    * **-sort {sorting method} -lines={n}** : Displays n lines


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
    *  **(no arguments), --help**
*  **EXAMPLES**
    * N/A
*  **DEFAULTS**
    * N/A
*  **OPTIONS**
    * N/A