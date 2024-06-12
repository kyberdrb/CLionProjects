# Set and reset alignment

An experiment to reset the alignment to default value after adjusting it to single bytes.

Before and after `#pragma pack()`

```
alignof(23FooAlignedToSingleBytes) =                          1
sizeof(23FooAlignedToSingleBytes) =                           5

alignof(47FooUnaligned_DefaultAlignedRestoredByPragmaPack) =  4
sizeof(47FooUnaligned_DefaultAlignedRestoredByPragmaPack) =   8
```

Before and after `#pragma pop`

```
alignof(38FooAlignedToSingleBytesAfterPragmaPack) =           1
sizeof(38FooAlignedToSingleBytesAfterPragmaPack) =            5

alignof(46FooUnaligned_DefaultAlignedRestoredByPragmaPop) =   1
sizeof(46FooUnaligned_DefaultAlignedRestoredByPragmaPop) =    5
```

The `#pragma pack()` define reset the alignment to default value. +
The `#pragma pop` define had no effect on the alignment or size.
