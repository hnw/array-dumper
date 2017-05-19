--TEST--
Check for is_packed_array()
--SKIPIF--
<?php
    if (!extension_loaded("arraydumper")) print "skip";
--FILE--
<?php
$str = "foo";
var_dump(is_packed_array($str));
$arr1 = ["foo", "bar"];
var_dump(is_packed_array($arr1));
$arr2 = [1=>"foo", 3=>"bar"];
var_dump(is_packed_array($arr2));
$arr3 = [3=>"foo", 1=>"bar"];
var_dump(is_packed_array($arr3));
--EXPECT--
bool(false)
bool(true)
bool(true)
bool(false)
