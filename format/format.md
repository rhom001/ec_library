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

<p>As a result we will have for the core XML files:</p>
<p>&lt;<em>object</em>List</em>&gt;</p>
<p>&nbsp;&nbsp;&lt;<em>object</em>&gt;</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&lt;title&gt;Name&lt;/title&gt;</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&lt;header&gt;Another optional header&lt;header&gt;</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&lt;trackList&gt;</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&lt;track&gt;Item Name&lt;track&gt;</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&lt;trackList&gt;</p>
<p>&nbsp;&nbsp;&lt;<em>object</em></p>
<p>&lt;/<em>object</em>List&gt;</p>
