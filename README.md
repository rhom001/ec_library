# Evillious Chronicles Library
<p>A database for all things Evillious</p>

<h2>Current Plan</h2>
<p>Using an <strong>Admin</strong> abstract base class, we will be able to 
derive <strong>Song</strong>, <strong>Album</strong>, <strong>Series</strong>, 
<strong>Role</strong>, and <strong>User</strong> objects.</p>

<h3>Class Content</h3>
<ul>
    <li><a href="#admin">Admin abstract base class</a></li>
    <ul>
        <li><a href="#song">Song class</a></li>
        <li><a href="#album">Album class</a></li>
        <li><a href="#series">Series class</a></li>
        <li><a href="#user">User class</a></li>
    </ul>
    <li><a href="#date">Date class</a></li>
    <li><a href="#menu">Menu class</a></li>
    <li><a href="#processor">Processor abstract base class</a></li>
    <ul>
        <li><a href="#xml">XML Reader class</a></li>
        <li><a href="#lyric">Lyric Viewer class</a></li>
        <li><a href="#player">Video Player class</a></li>
    </ul>
    <li><a href="#format">Format header file</a></li>
</ul>

<h3 id="admin">Admin</h3>
<ul>
<p>The <strong>Admin</strong> will allow a user to <em>print</em> an <strong>
Admin</strong> object, as well as <em>add</em>, <em>modify</em>, and <em>
remove</em> objects.</p>

<h4 id="song">Song</h4>
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

<h4 id="album">Album</h4>
<ul>
    <li>Title</li>
    <li>Date</li>
    <li>Tracklist</li>
</ul>

<p>The <strong>Album</strong> contains an album title, its release date, and 
all of its tracks.</p>

<h4 id="series">Series</h4>
<ul>
    <li>Title</li>
    <li>Series list</li>
</ul>

<p>The <strong>Series</strong> contains the series title and all songs in it.
</p>

<h4 id="role">Role</h4>
<ul>
    <li>Name</li>
    <li>Vocaloid</li>
    <li>Song list</li>
</ul>

<p>The <strong>Role</strong> contains the name of the character role, the 
vocaloid who plays them, and the list of songs that the character appears in.
</p>

<h4 id="user">User</h4>
<ul>
    <li>Username</li>
    <li>Password</li>
    <li>Abilty to add/modify all Admin objects except <strong>User</strong></li>
    <li>Ability to delete objects and to add or delete <strong>User</strong>
        accounts.</li>
</ul>

<p>The <strong>User</strong> contains an account's username, password, and 
privileges.</p>

<h3 id="#date">Date</h3>
<ul>
    <li>Month</li>
    <li>Day</li>
    <li>Year</li>
</ul>

<p>The <strong>Date</strong> class will be able to store a month, day, and 
year, as well as compare dates and print out the date in a different formats.
</p>

<h3 id="menu">Menu</h3>
<ul>
    <li>Songs</li>
    <li>Albums</li>
    <li>Series</li>
    <li>Roles</li>
    <li>Search</li>
    <li>Administration</li>
</ul>

<p>The <strong>Menu</strong> is the interface that allows the user to view 
information about a <strong>Song</strong>, <strong>Album</strong>, <strong>
Series</strong>, or <strong>Role</strong>, as well as easily search for those
objects. It will also allow some users to use the Administration menu to modify
any of the <strong>Admin</strong> objects.</p>

<h3 id="processor">Processor</h3>
<p>The <strong>Processor</strong> is an abstract base class for handling 
background processes for initialization of objects as well as triggering things 
that are not within the object code.</p>

<h4 id="xml">xmlReader</h4>
<ul>
    <li>XML file</li>
</ul>

<p>The <strong>xmlReader</strong> takes in an XML file and breaks its components
down into their respective objects.</p>

<h4 id="lyric">lyricReader</h4>

<h4 id="player">videoPlayer</h4>

<h3 id="format">Format</h3>
<p>The <strong>Format</strong> header is a file used to handle miscellaneous 
formatting functions.</p>

