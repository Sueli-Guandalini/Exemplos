<?php
    $codigo = $_GET["agenda"];
    if(file_exists("agendas.xml")){
        $xml = simplexml_load_file("agendas.xml");
        foreach($xml->children() as $agenda){
            if($agenda->codigo == $codigo){
                unset($agenda[0]);
                file_put_contents("agendas.xml", 
                        $xml->asXML());
                header("Location: lista_agendas.php");
            }
        }
    }
?>