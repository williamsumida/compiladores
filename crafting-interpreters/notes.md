## Notes

- Modern CPUs process data faster than reading it from RAM
- CPUs have cache to compensate that
- Pulling data from cache is 100x times faster than reading the RAM
- Whenever the CPU reads data, it pulls a few adjacent bytes and store then in the cache
- If the program has data "close" to each other, it will be cache friendly

Dynamic arrays provide:

- Cache-friendly, dense storage
- Constant-time indexed element lookup
- Constant-time appending to the end of the array

## Glossary

- bytecode
- opcode: operation code, a one-byte code to represent an instruction
