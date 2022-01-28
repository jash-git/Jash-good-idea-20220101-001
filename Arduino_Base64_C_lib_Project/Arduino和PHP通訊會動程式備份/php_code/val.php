<?php
	$val = $_GET['string'];
	$bf = fopen("test.txt","a+");
	fwrite ($bf,$val."\r\n");
	fclose($bf);
	echo "get data=";
	if(($val%2)==0)
	{
		echo 0;
	}
	else
	{
		echo 1;
	}	
?>