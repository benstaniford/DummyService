# DummyService

A dummy Windows service (based on the ATL service template) which builds the service and installer via GitHub actions.

# Projects
 - DummyInstaller - WiX installer project
 - DummyService - The service
 - DummyServiceLib - The contents of the service which is shared by the unit tests
 - DummyServiceTest - Unit tests for the service

# TODO
 - Add some registry actions to the service so it's installed correctly
 - Signing?
 - Initialize service CoInitializeSecurity
