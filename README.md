# ec_library
<p>Database for all things Evillious</p>

<h2>Current Plan</h2>
<p>Using an Admin class, we will be able to modify Song, Album, Series, and Character objects.</p>

<h3>Song</h3>
<ul>
    <li>Title</li>
    <li>Subtitle/English title</li>
    <li>Id number</li>
    <li>Date</li>
    <li>Vocaloid/Character</li>
    <li>Album</li>
    <li>Canon object</li>
    <ul>
        <li>Series</li>
        <li>EC</li>
    </ul>
    <li>Video object</li>
    <ul>
        <li>Upload</li>
        <li>Illustrators</li>
    </ul>
</ul>

<p>The <strong>Song</strong> should hold all of the information pertaining to a song as listed above. The <strong>Canon</strong> and <strong>Video</strong> are decorators for a <strong>Song</strong>.</p>

<h3>Album</h3>
<ul>
    <li>Title</li>
    <li>Date</li>
    <li>Tracklist</li>
</ul>

<p>The <strong>Album</strong> contains an album title, its release date, and all of its track.</p>

<h3>Series</h3>
<ul>
    <li>Title</li>
    <li>Series list</li>
</ul>

<p>The <strong>Series</strong> contains the series title and all songs in it.</p>

<h3>Character</h3>
<ul>
    <li>Name</li>
    <li>Vocaloid</li>
    <li>Song list</li>

