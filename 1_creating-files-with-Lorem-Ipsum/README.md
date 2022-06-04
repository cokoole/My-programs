#creating-files-with-Lorem-Ipsum

####Helper program made for graduation project for Skillbox

The program makes a post request to the site "https://www.lipsum.com", 
then translates the text into toLower, removes punctuation marks and
saves a certain number of files to prepare the file base for another program

I often use the lipsum site and I like C ++, but there is no separate library for it, 
so in the future there is a desire to refine this program, and so make an API call

The program has a problem due to a direct call to the site URL, therefore, in order
not to get IP banned, I do not recommend making more than 150 calls per day