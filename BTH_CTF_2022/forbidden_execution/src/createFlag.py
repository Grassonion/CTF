#!/usr/bin/python3


# encode flag
# BTH_CTF{ is already hardcoded into binary
flag ="WH0_N33ds_S3CURITY_B4DGES"

part1 = flag[0:int(len(flag)/3)]
part2 = flag[int(len(flag)/3): int(2*(len(flag)/3))]
part3 = flag[int(2*(len(flag)/3)):]

part1 = "".join(hex(ord(c)) for c in part1).replace("0x","")
part1 = part1[::-1]


part2 = "".join("x"+str(ord(c)*2) for c in part2)

print(part3)
part3 =  "".join(hex(ord(c)^5) for c in part3).replace("0x","")



print(part1)
print(part2)
print(part3)



