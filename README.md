# AwsGameLift 5.0 for UE5 5.1
 A working Windows AWS GameLift version 5.0.0.0 plugin for UE5 version 5.1
 
Since there has been no support for UE5 in recent releases of the GameLift SDK,
I've decided to create a plugin for UE5 (tested to be working with 5.1), which uses
the latest version of the GameLift SDK.

This is essentially a port of the old plugin for UE4 version 4.26 to UE5 by
updating the .lib and .dll files to version 5.0 (latest as of making this repo),
of the SDK. Then all the old header files have been updated to how they should be in
version 5.0 of the SDK. I also had to completely remove two deprecated functions,
which are thankfully replaced in the newest version, and are simply there for backwards
compatibility.

It is unfortunate that Amazon are not doing more to support the Unreal Engine 5,
while they support Unity. I searched high and low trying to find a way to get the 
SDK to work with UE5, but nothing worked. And since it would seem that only a few
hours work is needed to get the latest version working, it really does beg the question:
why have Amazon not done this themselves?

Anyway. Hopefully this plugin works for you. If you have any problems please contact me.