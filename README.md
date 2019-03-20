# phosphor-switch-manager
2019.3.15
description:add ssd1-12 use vector
commit:d952226bc7ca5bca9bd170afecc4a0c8d43da561
test version:openbmc-2.7-dev
test log:
usird2@SRD-0000057:~/workspace/dean/image-bmc/openbmc-dev$ curl -b cjar -k https://192.168.3.65/xyz/openbmc_proect/switch/ssd/
{
  "data": [
    "/xyz/openbmc_project/switch/ssd/ssd1",
    "/xyz/openbmc_project/switch/ssd/ssd10",
    "/xyz/openbmc_project/switch/ssd/ssd11",
    "/xyz/openbmc_project/switch/ssd/ssd12",
    "/xyz/openbmc_project/switch/ssd/ssd2",
    "/xyz/openbmc_project/switch/ssd/ssd3",
    "/xyz/openbmc_project/switch/ssd/ssd4",
    "/xyz/openbmc_project/switch/ssd/ssd5",
    "/xyz/openbmc_project/switch/ssd/ssd6",
    "/xyz/openbmc_project/switch/ssd/ssd7",
    "/xyz/openbmc_project/switch/ssd/ssd8",
    "/xyz/openbmc_project/switch/ssd/ssd9"
  ],
  "message": "200 OK",
  "status": "ok"
}

2019.3.20
description:init ssd1-12 property "Type" to "U.2"
commit:cd90f84c3ab37e649195b22738464124322bb534
test version:openbmc-2.7-dev
test log:
usird2@SRD-0000057:~/workspace/dean/image-bmc$ curl -b cjar -k https://192.168.3.57/xyz/openbmc_project/switch/sd/ssd1
{
  "data": {
    "ConfigureWidth": "",
    "Inserted": "",
    "LinkSpeed": "",
    "LinkStatus": "",
    "LinkWidth": "",
    "PartitionID": "",
    "SlotAddr": 0,
    "Status": "",
    "Type": "U.2"
  },
  "message": "200 OK",
  "status": "ok"
}


