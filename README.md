What is it?
-----------

It's a file tagger. It doesn't care what kind of files, it just handles keeping track of their tags.


Why "tigger"?
-------------

Two reasons:

* As a play on the idea of being a tagger, and on "tig", one of the many other names by which the game of [tag](http://en.wikipedia.org/wiki/Tag_\(game\)) is known (and the one used where I grew up).
* I will take pretty much any excuse to name a project after an A. A. Milne character.


How do I use it?
----------------

Usage: `tigger [-hnv] COMMAND [ARGUMENT ...]`

Option explanations:

 * `-n`, `--no-recurse`: Don't work with tags/files in directories below the current one.
 * `-v`, `--verbose`:    Print messages when doing something. Primarily for debugging.
 * `-h`, `--help`:       Print a help message describing these options.


Valid commands are:

 * tag
   - Usage: `tigger [-nv] tag TAG FILE [FILE ...]`
   - Tags all `FILE`s with the tag `TAG`.
 * untag,
   - Usage: `tigger [-nv] untag TAG FILE [FILE ...]`
   - Removes the tag `TAG` from all `FILE`s that have it.
 * files
   - Usage: `tigger [-nv] files TAG`
   - Lists all files which have the tag `TAG`.
 * tags
   - Usage: `tigger [-nv] tags FILE [FILE ...]`
   - Lists all tags for each `FILE`.
 * mv
   - Usage: `tigger [-nv] mv SRCFILE DESTFILE`
   - Moves/renames `SRCFILE` to `DESTFILE`, and updates the tagging data to reflect the change.
 * cp
   - Usage: `tigger [-nv] cp SRCFILE DESTFILE`
   - Copies `SRCFILE` to `DESTFILE`, and updates the tagging data to reflect the change.
 * rm
   - Usage: `tigger [-nv] rm FILE [FILE ...]`
   - Deletes all `FILE`s, and updates the tagging data to reflect the change.
