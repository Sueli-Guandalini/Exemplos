<section>
	<?php
		$editando = false;
		if(!empty($_GET)){
			$agenda = buscar_agenda($_GET["agenda"]);
			if(!empty($agenda)){
				$editando = true;
			}
		}
	?>
	<form action="form_agenda.php" method="post">
		<fieldset>
			<legend>Agendar Clientes</legend>
			<p>
				<label>Código:</label>
				<input type="number" name="codigo"
					readonly="readonly"
					<?php
						if($editando){
							echo 'value="'.$agenda->codigo.'"';
						}else{
							$codigo = buscar_codigo("agenda");
							echo 'value="'.$codigo.'"';
						}	
					?>
				/>
			</p>
			<p>
				<label>Nome:</label>
				<input type="text" name="nome" size="30"
					<?php
						if($editando){
							echo 'value="'.$agenda->nome.'"';
						}
					?>
				/>
				<label>E-mail:</label>
				<input type="email" name="email" 
					<?php
						if($editando){
							echo 'value="'.$agenda->email.'"';
						}
					?>
				/>
			</p>
			<p>
				<label>Telefone:</label>
				<input type="text" name="telefone" 
					<?php
						if($editando){
							echo 'value="'.$agenda->telefone.'"';
						}
					?>
				/>
				<label>Data:</label>
				<input type="date" name="data"	size="30"
					<?php
						if($editando){
							echo 'value="'.$agenda->data.'"';
						}
					?>
				/>
				<label>Hora:</label>
				<input type="time" name="hora" size="10"
					<?php
						if($editando){
							echo 'value="'.$agenda->hora.'"';
						}
					?>
				/>
			</p>
			<input type="hidden" name="modo"
				<?php
					if($editando){
						echo 'value="1"';
					}else{
						echo 'value="0"';
					}
				?>
			/>
			<input type="submit" value="Agendar"/>
		</fieldset>
	</form>
</section>