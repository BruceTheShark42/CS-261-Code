public class Request {
	private int id;
	private String message;
	
	public Request(int id, String message) {
		this.id = id;
		this.message = message;
	}
	
	public int getID() {
		return id;
	}
	
	public String getMessage() {
		return message;
	}
}
