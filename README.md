# DummyService

A dummy Windows service (based on the ATL service template) which builds the service and installer via GitHub actions.

# Projects
 - DummyInstaller - WiX installer project
 - DummyService - The service
 - DummyServiceLib - The contents of the service which is shared by the unit tests
 - DummyServiceTest - Unit tests for the service

 # Features
 - Publishes installers on all platforms and configurations
 - Unit tests run via GitHub
 - Packages correct merge modules for VCRuntimes
 - Service installed with SCM and can be started/stopped

# TODO
 - Add some registry actions to the service so it's installed correctly
 - Signing?
 - UI and license on installer
 - PDBs published
