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
<br />&nbsp;&nbsp;&nbsp;&nbsp;&lt;track&gt;Project 'Ma'&gt;
<br />&nbsp;&nbsp;&lt;/trackList&gt;
<br />&lt;/character&gt;</p>
