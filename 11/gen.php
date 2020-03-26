<?php

$output = fopen("./data.txt", "w");

for ($i = 0; $i < 50; $i++)
{
    $n = rand(1, 1000);
    fwrite($output, "$n ".md5($n)."\n");
}

fclose($output);

