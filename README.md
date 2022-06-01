### drgnfly

simple script initially used to run minecraft servers over ssh.

**All scripts must be shell script**

As an example; running a minecraft server...
```sh
#!/bin/bash
#server.sh
java -Xmx16G -Xmx16G -jar server.jar
```
Then run
`sh dfly.sh server.sh`

