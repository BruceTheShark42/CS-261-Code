public enum Priority {
	HIGH(0),
	MEDIUM(1),
	LOW(2);
	
	int priorityNumber;
	
	private Priority(int priorityNumber) {
		this.priorityNumber = priorityNumber;
	}
	
	public int getPriorityNumber() {
		return priorityNumber;
	}
}
