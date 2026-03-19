program = [
    0x01, 0x12,   
    0x02,   
     0x01, 0x12,   
    0x03,       
    0x04        
]

with open("rom.bin", "wb") as f:
    f.write(bytes(program))

f.close()