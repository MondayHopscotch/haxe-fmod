package other;

class Version {
	public static macro function getGitCommitHash():haxe.macro.Expr.ExprOf<String> {
	  #if !display
	  var process = new sys.io.Process('git', ['rev-parse', 'HEAD']);
	  if (process.exitCode() != 0) {
		var message = process.stderr.readAll().toString();
		var pos = haxe.macro.Context.currentPos();
		haxe.macro.Context.error("Cannot execute `git rev-parse HEAD`. " + message, pos);
	  }

	  // read the output of the process
	  var commitHash:String = process.stdout.readLine();

	  // Generates a string expression
	  return macro $v{commitHash};
	  #else
	  // `#if display` is used for code completion. In this case returning an
	  // empty string is good enough; We don't want to call git on every hint.
	  var commitHash:String = "";
	  return macro $v{commitHash};
	  #end
	}
  }