<?php
	function buscar_codigo($entidade){
		if(file_exists("sequencia_codigos.xml")){
			$xml = simplexml_load_file("sequencia_codigos.xml");
			switch($entidade){
				case "agenda":
					return $xml->agenda;
			}
		}else{
			$xml =
				'<?xml version="1.0" encoding="UTF-8" ?>
				<codigos>
					<agenda>1</agenda>
				</codigos>';
			
			file_put_contents("sequencia_codigos.xml", $xml);
			return 1;
		}
	}

	function atualiza_codigo($entidade){
		if(file_exists("sequencia_codigos.xml")){
			$xml = simplexml_load_file("sequencia_codigos.xml");
			switch($entidade){
				case "agenda":
					$xml->agenda++;
					break;
			}
			file_put_contents("sequencia_codigos.xml", $xml->asXML());
		}
	}

	function ler_dados_agenda(){
		$codigo = $_POST["codigo"];
		$nome = $_POST["nome"];
		$email = $_POST["email"];
		$telefone = $_POST["telefone"];
		$data = $_POST["data"];
		$hora = $_POST["hora"];
		$modo = $_POST["modo"];
		if($modo == 0){
			if(!file_exists("agendas.xml")){
				$xml =
					'<?xml version="1.0" encoding="UTF-8" ?>
					<agendas>
						<agenda>
							<codigo>'.$codigo.'</codigo>
							<nome>'.$nome.'</nome>
							<email>'.$email.'</email>
							<telefone>'.$telefone.'</telefone>
							<data>'.$data.'</data>
							<hora>'.$hora.'</hora>
						</agenda>
					</agendas>';
					file_put_contents("agendas.xml", $xml);
					
			}else{
				$xml = simplexml_load_file("agendas.xml");
				$agenda = $xml->addChild("agenda");
				$agenda->addChild("codigo", $codigo);
				$agenda->addChild("nome", $nome);
				$agenda->addChild("email", $email);
				$agenda->addChild("telefone", $telefone);
				$agenda->addChild("data", $data);
				$agenda->addChild("hora", $hora);
				file_put_contents("agendas.xml", $xml->asXML());
			}
			atualiza_codigo("agenda");
			echo "<section>
					<h2>Agendamento realizado com sucesso.</h2>
    				<td><a href=\"form_agenda.php?
						agenda=$agenda->codigo\">Novo Agendamento</a></td><br><br>
					<td><a href=\"lista_agendas.php?
						agenda=$agenda->codigo\">Ver Agenda</a></td>
				</section>";
		}else{
			$xml = simplexml_load_file("agendas.xml");
			foreach($xml->children() as $agenda){
				if($agenda->codigo == $codigo){
					$agenda->nome = $nome;
					$agenda->email = $email;
					$agenda->telefone = $telefone;
					$agenda->data = $data;
					$agenda->hora = $hora;
				}
			}
			file_put_contents("agendas.xml", $xml->asXML());
			echo "<section>
					<h2>Agenda editada com sucesso.</h2>
				</section>";
		}
	}
	
	function lista_agendas(){
		$xml = simplexml_load_file("agendas.xml");
		foreach($xml->children() as $agenda){
			echo "<tr>
					<td>$agenda->codigo</td>
					<td>$agenda->nome</td>
					<td>$agenda->email</td>
					<td>$agenda->telefone</td>
					<td>$agenda->data</td>
					<td>$agenda->hora</td>
					<td><a href=\"form_agenda.php?
							agenda=$agenda->codigo\">editar</a></td>
					<td><a href=\"excluir_agenda.php?
							agenda=$agenda->codigo\">excluir</a></td>
				</tr>";
		}
	}

	function buscar_agenda($codigo){
		if(file_exists("agendas.xml")){
			$xml = simplexml_load_file("agendas.xml");
			foreach($xml->children() as $agenda){
				if($agenda->codigo == $codigo){
					return $agenda;
				}
			}
		
		}
	}
?>