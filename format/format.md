<h1>How to Read XML Files</h1>
<p>Using the sample format XML files as an example, this will be used to
demonstrate how XML files will be used to generate objects and update the
XML files afterward.</p>

<h2>Core Files</h2>
<p>The main types of objects that we will be looking at are the
<strong>Song</strong>, <strong>Album</strong>, <strong>Series</strong>,
<strong>Role</strong>, and <strong>User</strong> objects. Therefore we will
have individual XML files for those.</p>

<p>Each file will contain an XML list that will be somewhat standardized
and will contain for each object a <em>title</em> and a list of contained
inside a <em>trackList</em> that will consist of <em>track</em>s that can
be used to hold detailed objects.</p>

<p>As a result we will have for the core XML files:
<br />&lt;<em>object</em>List</em>&gt;
<br />&nbsp;&nbsp;&lt;<em>object</em>&gt;
<br />&nbsp;&nbsp;&nbsp;&nbsp;&lt;title&gt;Name&lt;/title&gt;
<br />&nbsp;&nbsp;&nbsp;&nbsp;&lt;header&gt;Another optional header&lt;
header&gt;
<br />&nbsp;&nbsp;&nbsp;&nbsp;&lt;trackList&gt;
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&lt;track&gt;Item Name&lt;
track&gt;
<br />&nbsp;&nbsp;&nbsp;&nbsp;&lt;trackList&gt;
<br />&nbsp;&nbsp;&lt;<em>object</em>&gt;
<br />&lt;/<em>object</em>List&gt;</p>

<p>Within the XML viewer tree, which handles opening, reading, and 
outputting XML files then this uniformity makes it more streamlined
for these processes. While the <em>title</em> for an <em>object</em> will
be given, the number of secondary <em>header</em>s can be adjusted through
manual user creation or automatically for certain <em>object</em>s.</p>

<h2>Character Files</h2>
<p>In order to minimize the headers and lists on the <em>Song</em> object,
the characters that appear in each song have their own file. This file has
the name of the character as well as which song(s) they haave appeared in.
</p>

<p>An example of this would be: </p>
<p>&lt;character&gt;
<br />&nbsp;&nbsp;&lt;title&gt;Eve Zvezda&lt;/title&gt;
<br />&nbsp;&nbsp;&lt;trackList&gt;
<br />&nbsp;&nbsp;&nbsp;&nbsp;&lt;track&gt;Project 'Ma'&lt;/track&gt;
<br />&nbsp;&nbsp;&lt;/trackList&gt;
<br />&lt;/character&gt;</p>

<p>To note, the character Eve Zvezda, while the same character as Eve
Moonlit is still distinct. So there would be a separate file for that 
character such that: </p>
<p>&lt;character&gt;
<br />&nbsp;&nbsp;&lt;title&gt;Eve Moonlit&lt;/title&gt;
<br />&nbsp;&nbsp;&lt;trackList&gt;
<br />&nbsp;&nbsp;&nbsp;&nbsp;&lt;track&gt;Moonlit Bear&lt;/track&gt;
<br />&nbsp;&nbsp;&lt;/trackList&gt;
<br />&lt;/character&gt;</p>

<h3>What Makes a Character</h3>
<p>Once again, to keep the loading efficient, we need a strict definition
of what makes a character. In this case, it will be for vocal only. If not 
sure, please check <a href=
"http://theevilliouschronicles.wikia.com/wiki/Category:Characters"
>the Evillious Chronicles wiki</a> for verification.</p>

<h3>New Characters</h3>
<p>Although a new character can be formed directly through a <strong>Role
</strong> object, the object will most likely be built through a <strong>
Song</strong> object.</p>

<p>This is because when the add() function of the <strong>Song</strong>
object is used, the user is asked for which vocalists/characters appear.
<em>If the <strong>Role</strong> already exists, then the <strong>Role
</strong> is just pushed back on to the <strong>Song</strong>.</em>
Otherwise, a new <strong>Role</strong> object must be created.

<p>In order for the new <strong>Role</strong> to be formed, the name of the
character is put in by the user. Then the Vocaloid is checked to make sure 
that that Vocaloid exists. This is to check for any potential errors and 
repetivity as well as retain uniformity in <em>role.xml</em>. Finally the
object is formed and added on to the <strong>Song</strong> object as well
as the vector of <strong>Role</strong> pointers.</p>

<h3>Updating Characters</h3>
<p>If there is a need to change the name of a character in a <strong>Role
</strong>, then this can be done through the modify() function of the 
<strong>Role</strong> object.</p>

<p>If there is a need for a name change for a Vocaloid, then this has to be
done by finding all characters under the particular name of the previous 
Vocaloid and then changing the name of the Vocaloid through the modify()
function of the <strong>Role</strong> object.</p>

<h2>Updating XML Files</h2>
<p>Once the user is finished using the program upon exiting, then the
<strong>Menu</strong> is terminated. Then the XML files will be updated 
before the program finishes terminating. Each of the core files must be 
updated in a prticular order so as not to break the informational objects.
</p>

<h3>Updating role.xml</h3>
<p>One of the more time-consuming exit processes will be writing the 
<em>role.xml</em> and the character files. Considering that the <strong>
Menu</strong> object has already sorted the characters by which Vocaloid 
they are played by, then each Vocaloid and their roles are pushed on to the 
<strong>xmlCreator</strong> to make something similar to <em>sample-role.xml
</em>.</p>

<p>When a character role is pushed on to the <em>track</em> container of 
<em>role.xml</em>, then the character name is converted into an xml file 
name that is in turn used to create and generate a character xml file for 
that particular character. In the character xml file, the name of the 
character is used as the <em>title</em>. Then for each <strong>Song
</strong> that the <strong>Role</strong> is found, the title of the 
<strong>Song</strong> is pushed as a <em>track</em> in the character file.
</p>

<h3>Updating series.xml and album.xml</h3>
<p>For <em>series.xml</em>, the vector of <strong>Series</strong> pointers
are simply read off from the <strong>Menu</strong> object. The name of the 
series is then read in as the <em>title</em> while the songs in the series 
are put in a <em>track</em> container.</p>

<p>For the <em>album.xml</em>, the vector of <strong>Album</strong> 
pointers is done in a similar process to the <strong>Series</strong>. 
However, a second header is made for the release date of the <strong>
Album</strong>.

<h3>Updating song.xml</h3>
<p>Unlike the previous core files, the <em>song.xml</em> file does not have
a <em>trackList</em> container. Instead it is comprised of headers. While 
there is definitely a <em>title</em> container for the <strong>Song
</strong>. If the song in question has an alternative/English title, then 
that is included in the <em>subtitle</em> container. Otherwise the <strong>
Song</strong> object should have separate headers for its <em>id</em> and 
release <em>date</em>.</p>

<p>Since <strong>Song</strong> objects may have a <strong>Canon</strong> 
and/or <strong>Video</strong> object, these are similarly optional items 
like the <em>subtitle</em> container.</p>

<p>If a <strong>Canon</strong> object exists, then the <em>canon</em>
container is made. However, it is not necessary for anything to be inside 
the container. That is unless there is a year that is not -1000.</p>

<p>If a <strong>Video</strong> object exists, then the <em>video</em> 
container is made. It is necessary to include a <em>date</em> container 
for the upload date of the original PV as well as a <em>trackList</em> 
container in which all of the video illustrators (or people involved in the
video production) are included as <em>track</em> containers.</p>

<h3>Updating user.xml</h3>
<p>The <em>user.xml</em> consists of only header containers. These 
containers are <em>title</em> (for the username), <em>pass</em> (password), 
and <em>privy</em> (user privileges in binary). When updating for the <em>
privy</em> if the user has a privilege, then that is printed as a '1' to 
form a string. Otherwise, it is a '0' to show that the <strong>User
</strong> does not have the privilege.</p>
