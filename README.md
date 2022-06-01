#### drgnfly

**Really** simple script initially used to run minecraft servers over ssh.

**All scripts must be shell script**
As an example; running a minecraft server...
```sh (server.sh)
#!/bin/bash
java -Xmx16G -Xmx16G -jar server.jar
```
Then run
`sh dfly.sh server.sh`

