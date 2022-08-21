# Plugin

A toy plugin framework.

Have a try:

```bash
$ meson setup build

$ meson compile -C build

$ ./build/example/app/hello
Load which plugin(1 or 2): 1
Load Plugin: HelloFromHere
Plugin Author: HammerLi
Plugin Version: v0.0.1
=== Trigger Plugin Method Begin ===
hello from here
=== Trigger Plugin Method End ===
Load which plugin(1 or 2): 2
Load Plugin: HelloFromThere
Plugin Author: HammerLi
Plugin Version: v0.0.1
=== Trigger Plugin Method Begin ===
hello from there
=== Trigger Plugin Method End ===
Load which plugin(1 or 2): 3

```