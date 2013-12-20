--TEST--
NSTest::bar() member function
--SKIPIF--
<?php 

if(!extension_loaded('NSTest')) die('skip ');

 ?>
--FILE--
<?php
echo 'OK'; // no test case for this function yet
?>
--EXPECT--
OK